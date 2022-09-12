<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="9">
					<div class="caption text-decoration-underline">{{tag.Cpt}}</div>
					<div>{{continf.TxtRef}}</div>
				</v-col>
				<v-col cols="3" align="end">
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeCLick')"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						:disabled="!statshr.ButRegularizeActive"
						v-on:click="handleButClick('ButRegularizeClick')"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWzskVExpstate=='regd'"
		>
			<v-row>
				<v-col cols="12" md="12">
					<PnlWzskOgrDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzskOgrDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWzskOgr1NObject
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzskOgr1NObject"
						:scrJref=statshr.scrJref1NObject
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWzskOgrSup1NObjgroup
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzskOgrSup1NObjgroup"
						:scrJref=statshr.scrJrefSup1NObjgroup
					/>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskOgrDetail from './PnlWzskOgrDetail';
	import PnlWzskOgr1NObject from './PnlWzskOgr1NObject';
	import PnlWzskOgrSup1NObjgroup from './PnlWzskOgrSup1NObjgroup';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskOgrRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskOgrDetail,
			PnlWzskOgr1NObject,
			PnlWzskOgrSup1NObjgroup
			/*
			*/
		},

		mounted() {
			//console.log("PnlWzskOgrRec.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWzskOgrRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWzskOgrRec) this.continf = dpcheng.ContInfWzskOgrRec;
				if (dpcheng.StatAppWzskOgrRec) this.statapp = dpcheng.StatAppWzskOgrRec;
				if (dpcheng.StatShrWzskOgrRec) this.statshr = dpcheng.StatShrWzskOgrRec;
				if (dpcheng.TagWzskOgrRec) {
					Wzsk.unescapeBlock(dpcheng.TagWzskOgrRec);
					this.tag = dpcheng.TagWzskOgrRec;
				}
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				//console.log(obj);
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
					else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);

				} else if (this.initdone) {
					if (this.statshr.srefIxWzskVExpstate == "regd") {
						/*
						*/
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWzskOgrDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NObject) this.$refs.PnlWzskOgr1NObject.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSup1NObjgroup) this.$refs.PnlWzskOgrSup1NObjgroup.handleReply(obj);
						/*
						*/
					}
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskOgrRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskOgrRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWzskVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWzskOgrDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NObject) this.$refs.PnlWzskOgr1NObject.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSup1NObjgroup) this.$refs.PnlWzskOgrSup1NObjgroup.handleUpdate(obj);
						/*
						*/
						else processed = false;
					}
				}

				return processed
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
