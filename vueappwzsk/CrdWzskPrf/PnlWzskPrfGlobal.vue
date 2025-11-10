<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="3">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButRegularizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWzskVExpstate=='regd'"
		>
			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg1}}
			</h3>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf2"
				:label="tag.Cpt2"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf3"
				:label="tag.Cpt3"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf4"
				:label="tag.Cpt4"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf5"
				:label="tag.Cpt5"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf6"
				:label="tag.Cpt6"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg101}}
			</h3>

			<v-select
				class="my-1"
				v-model="contapp.fiFPup102"
				return-object
				:items="feedFPup102"
				item-value="num"
				item-text="tit1"
				:label="tag.Cpt102"
				v-on:change="handleFiChange('numFPup102', contapp.fiFPup102)"
			/>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskPrfGlobal',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskPrfGlobal.mounted() with scrJref = " + this.scrJref);

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

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskPrfGlobalDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleFiChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskPrfGlobal"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskPrfGlobalData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskPrfGlobalData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskPrfGlobal) this.contiac = dpcheng.ContIacWzskPrfGlobal;
				if (dpcheng.FeedFPup102) this.feedFPup102 = dpcheng.FeedFPup102;
				if (dpcheng.StatShrWzskPrfGlobal) this.statshr = dpcheng.StatShrWzskPrfGlobal;
				if (dpcheng.TagWzskPrfGlobal) {
					Wzsk.unescapeBlock(dpcheng.TagWzskPrfGlobal);
					this.tag = dpcheng.TagWzskPrfGlobal;
				}
				if (dpcheng.ContIacWzskPrfGlobal) {
					for (let i = 0; i < this.feedFPup102.length; i++)
						if (this.feedFPup102[i].num == this.contiac.numFPup102) {
							this.contapp.fiFPup102 = this.feedFPup102[i];
							break;
						}
				}
				/*
				<!-- IP mergeDpchEngData - END -->
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
				if (srefIxWzskVDpch == "DpchEngWzskPrfGlobalData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskPrfGlobalData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPup102: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPup102: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
