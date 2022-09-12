<template>
	<v-card v-if="initdone" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="4">
					<div>
						<span>{{tag.Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="8" align="end"/>
			</v-row>
		</v-card-title>
		<v-card-text>
			<v-select
				class="my-1"
				v-model="contapp.fiFPupSup"
				:items="feedFPupSup"
				:label='tag.CptSup'
				v-on:change="handlePupChange('numFPupSup', contapp.fiFPupSup)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSrf"
				:label="tag.CptSrf"
			/>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupLcl"
				:items="feedFPupLcl"
				:label='tag.CptLcl'
				v-on:change="handlePupChange('numFPupLcl', contapp.fiFPupLcl)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfTit"
				:label="tag.CptTit"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCmt"
				:label="tag.CptCmt"
			/>

		</v-card-text>
		<v-divider/>
		<v-card-actions>
			<v-spacer/>
			<v-btn class="primary"
				v-on:click="handleButClick('', 'ButCncClick')"
			>
				{{tag.ButCnc}}
			</v-btn>
			&#160;
			<v-btn class="primary"
				v-on:click="handleButClick('', 'ButCreClick')"
			>
				{{tag.ButCre}}
			</v-btn>
		</v-card-actions>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'DlgWzskOgrNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWzskOgrNew.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ditshort, ctlsref) {
				var dpchapp = {
					"DpchAppDlgWzskOgrNewDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWzskOgrNewDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(ditshort, cisref, fi) {
				this["contiac" + ditshort][cisref] = fi.num;

				this.updateEng(["contiac" + ditshort]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWzskOgrNew"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWzskOgrNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWzskOgrNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWzskOgrNew) this.contiac = dpcheng.ContIacDlgWzskOgrNew;
				if (dpcheng.ContInfDlgWzskOgrNew) this.continf = dpcheng.ContInfDlgWzskOgrNew;
				if (dpcheng.FeedFPupLcl) this.feedFPupLcl = dpcheng.FeedFPupLcl;
				if (dpcheng.FeedFPupSup) this.feedFPupSup = dpcheng.FeedFPupSup;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWzskOgrNew) this.statapp = dpcheng.StatAppDlgWzskOgrNew;
				if (dpcheng.StatShrDlgWzskOgrNew) this.statshr = dpcheng.StatShrDlgWzskOgrNew;
				if (dpcheng.TagDlgWzskOgrNew) {
					Wzsk.unescapeBlock(dpcheng.TagDlgWzskOgrNew);
					this.tag = dpcheng.TagDlgWzskOgrNew;
				}
				if (dpcheng.ContIacDlgWzskOgrNew) {
					for (let i = 0; i < this.feedFPupSup.length; i++)
						if (this.feedFPupSup[i].num == this.contiac.numFPupSup) {
							this.contapp.fiFPupSup = this.feedFPupSup[i];
							break;
						}
					for (let i = 0; i < this.feedFPupLcl.length; i++)
						if (this.feedFPupLcl[i].num == this.contiac.numFPupLcl) {
							this.contapp.fiFPupLcl = this.feedFPupLcl[i];
							break;
						}
				}
				/*
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngDlgWzskOgrNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngDlgWzskOgrNewData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {

		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			feedFPupLcl: null,

			feedFPupSup: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupSup: null,

				fiFPupLcl: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
